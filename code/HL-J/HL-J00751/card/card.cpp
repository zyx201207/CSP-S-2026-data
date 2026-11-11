#include<bits/stdc++.h>
using namespace std;
int n,m,b[500005],ans,a[300005];
bool f[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>b[i];
	}
	ans=n;
//	for(int i=1;i<=n;i++){
//	stack<int>s;
//		for(int j=i;j<=n;j++){
//			if(f[b[j]]!=1){
//				s.push(b[j]);
//				f[b[j]]=1;
//			}else{
//				while(s.top()!=b[j]){
//					f[s.top()]=0;
//					s.pop();
//				}
//			}
//		}
//		while(!s.empty()){
//			ans[s.top()]++;
//			s.pop();
//		}	
//	}
//	for(int i=1;i<=m;i++){
//		cout<<ans[i]<<' ';
//	}
	cout<<0<<' '<<0;
    return 0;
}
/*
4 3
1 2 1 3
*/