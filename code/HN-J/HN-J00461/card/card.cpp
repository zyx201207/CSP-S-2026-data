#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int ans[500010];
bool cards[300010];
string s="";
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" "; 
	} 
//	for(int i=0;i<n;i++){
//		for(int j=i;j<n;j++){
//			s+=char(a[j]);
//			if(cards[a[j]]){
//				int f=s.find(a[j]);
//				for(int x=f;x<=j;x++){
//				}
//			}
//			cards[a[j]]=1;
//			
//		}
//	}
	return 0;
} 


