#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=m;k++){
		queue<int> q;
		int s[500005];
		for(int i=k-1;i<=n;i++){
			q.push(a[i]);
		}
		int cnt=0,l=1;;
		while(q.size()){
			int t=q.front();
			q.pop();
			if(t==k){
				cnt++;
			}
			
			int x=-1;
			for(int i=l;i>=1;i--){
				if(s[i]==k){
					x=i;
					break;
				}
				
			}
			if(x==-1){
				s[l++]=t;
				continue;
			}
			for(int i=l;i>=x;i--){
				if(s[i]==k){
					cnt--;
				}
			}
			s[x++]=t;
//			for(int i=1;i,=l;i++){
//				cout<<
//			}
		}
		cout<<cnt<<' ';
	}
	return 0;
} 
