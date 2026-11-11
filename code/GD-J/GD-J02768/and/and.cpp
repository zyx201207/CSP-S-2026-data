#include<bits/stdc++.h>
using namespace std;
string er[100086];
//int yu(int y){
//	int sum=0;
//	string s;
//	while(y){
//		s+=(y%2)+'0';
//		y/=2;
//		sum++;
//	}
//	for(int i=sum;i>0;i--){
//		return s[i];
//	}
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m,a[100086],maxn=0,minn=0,ans=0;
	bool w=1,z=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		if(a[i]>=4) z=0;
//		er+=yu(a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]){
			w=0;
			break;
		}
	}
	if(w){
		cout<<a[1];
		return 0;
	}
	maxn=0;
//	for(int i=1;i<n;i++){
//		for(int j=0;j<min(er[i].size(),er[i-1].size());j++){
//			if(er[i][er[i].size()-j] == er[i-1][er[i-1].size()-j]){
//				ans+=pow(2,j);
//				maxn=max(maxn,ans);
//			}
//		}
//		
//	}
//	cout<<maxn;
	return 0;
}

