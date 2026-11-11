#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);

	int n,m,minn=99999,mx,sum=0;
	cin>>n>>m;
	int x[500001];
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int p=0;p<m;p++){
		minn=99999;mx=0;
		for(int i=1;i<=n;i++){
			if(minn>x[i]){
				minn=x[i];
				mx=i;
			}
		}
		x[mx]+=1;
	}
	minn=x[mx];
	for(int i=1;i<=n;i++){
		if(x[i]==minn) sum++;
	}
	cout<<sum;
}
