#include<bits/stdc++.h>
using namespace std;
struct node{
	int hs,ans = 0;
}b[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100010];
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>a[i];
	for(int i = 0;i<n;i++){
		int c[10010],s = 0;
		for(int j = i-1;j<n;j++){
			c[s] = a[j];
			for(int k =0;k<j;k++){
				if(c[k] == c[s]){
					s = k;
				}
			}
		}
		for(int k = 0;k<=s;k++)b[c[k]].ans++;	
	}
	sort(a,a+n);
	for(int i = 0;i<m;i++){
		if(b[a[i]].ans!=0)cout<<b[a[i]].ans<<" ";
	}
	return 0;
}
