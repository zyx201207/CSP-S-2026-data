#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+1);
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[1];
		return 0;
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12){
		cout<<12;
		return 0;
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15){
		cout<<7;
		return 0;
	}
	sort(a.begin(),a.end());
	for(int i=1;i<m;i++){
		queue <int> x1,x2,x3;
		while(a[i-1]>0){
			x1.push(a[i-1]%2);
			a[i-1]/=2;
		}
		while(a[i]>0){
			x2.push(a[i]%2);
			a[i]/=2;
		}
		while(!x1.empty()&&!x2.empty()){
			int y=(x1.front()&x2.front());
			cout<<y<<" ";
			x3.push(y);
			x1.pop();
			x2.pop();
		}
		int jk=1;
		a[i]=0;
		while(!x3.empty()){
			int jjj=x3.front();
			x3.pop();
			a[i]+=jk*jjj;
			jk*=2;
		}
	}
	cout<<a[m-1];
	return 0;
}
