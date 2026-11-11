#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
vector<int> v;
int k[60000000];
int maxx;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k[a[i]]++;
	}
	if(m==2){
		for(int i=1;i<=10000000;i++){
			if(k[i]==0){
				continue;
			}else{
				v.push_back(a[i]);
			}
		}
		for(int i=0;i<v.size();i++){
			for(int j=i+1;j<=v.size();j++){
				int x=v[i]&v[j];
				maxx=max(maxx,x);
				//cout<<x<<endl;
			}
		}
		v.clear();
		for(int i=1;i<=10000000;i++){
			if(k[i]>1){
				v.push_back(a[i]);
			}
		}
		for(int i=0;i<v.size();i++){
			int x=v[i]&v[i];
			maxx=max(maxx,x);
			//cout<<x<<endl;
		}
	}else if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}else if(m==n){
		int y=a[1]&a[2];
		for(int i=3;i<=n;i++){
			y=y&a[i];
		}
		cout<<y<<endl;
		return 0;
	}else if(m==(n-1)){
		for(int i=1;i<=n;i++){
			int y;
			if(i==1) y=a[2]&a[3];
			else if(i==2) y=a[1]&a[3];
			else if(i==3) y=a[1]&a[2];
			else y=a[1]&a[2]&a[3];
			for(int j=4;j<=n;j++){
				if(i==j) continue;
				y&=a[j];
			}
			maxx=max(maxx,y);
		}
	}
	cout<<maxx;
	return 0;
}
