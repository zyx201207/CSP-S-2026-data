#include<bits/stdc++.h>
using namespace std;
int n,m,s[500005],sum[300005],l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i]; 
	for(int i=0;i<n;i++){
		l=i;
		for(int j=i;j<n;j++){
			sum[s[j]]++;
			if(s[l]==s[j]){
				for(int k=l;k<j;k++){
					sum[s[k]]--;
				}
				l=j;
			}
		}
	}
	l=0;
	while(m){
		if(sum[l]!=0){
			cout<<sum[l]<<' ';
			m--;
			l++;
		}else{
			l++;
		}
	}
	return 0;
}
