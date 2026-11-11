#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxl=-1;
	cin>>n>>m;
	int a[n]={};
	stack<int> st;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		while(x!=0){
			st.push(x%2);
			x=x/2;
		}
		int f=st.size();
		for(int j=0;j<f;j++){
			a[i]=a[i]*10+st.top();
			st.pop();
		}
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int f1=a[i]+a[j],f2=0,f3=0;
			while(f1!=0){
				if(f1%10!=0) f2=f2*10+((f1%10)-1);
				f1=f1/10;
			}
			while(f2!=0){
				f3=f3*10+f2%10;
				f2=f2/10;
			}
			if(f3>maxl) maxl=f3;
		}
	}
	cout<<maxl;
	return 0;
}
