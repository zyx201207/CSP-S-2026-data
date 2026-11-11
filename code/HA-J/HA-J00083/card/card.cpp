#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct node{
	int x,y;
};
int jsa[300005];
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		node cnt[300005];
		int s[500005];
		for(int j=n-i;j<=n;j++){
			s[j]=a[j];
			cnt[s[j]].x++;
			if(cnt[s[j]].x<2){
				cnt[s[j]].y=j;
			}
			else if(cnt[s[j]].x>=2){
				for(int k=cnt[s[j]].y+1;k<=j;k++){
					if(cnt[s[k]].x>0){
						cnt[s[k]].x--;
					}
					s[k]=0;
				}
			}
		}
		for(int j=n-1;j<=i;j++){
			for(int k=1;k<=m;k++){
				if(s[j]==jsa[k]){
					jsa[k]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<jsa[i]<<" ";
	}

	return 0;
}
