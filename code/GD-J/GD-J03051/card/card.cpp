#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005],t[500005],b[500005];
int main(){
	ios::sync_with_stdio(false);
cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	int st=0;
	int l=0;
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
		st++;
		s[st]=a[j];
		t[a[j]]++;
		if(t[a[j]]>1){
			for(int k=1;k<st;k++){
				if(a[k]==s[st]){
					l=k;
					break;
				}
			}
			
			for(int k=l;k<st-1;k++){
				s[k]=0;
			}
		}
		
		}
	for(int j=1;j<=st;j++){
	if(s[j])b[s[j]]++;
	}
	for(int j=1;j<=max(st,m);j++){
	s[j]=0;
	t[j]=0;	
	}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
