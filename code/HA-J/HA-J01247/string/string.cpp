#include<bits/stdc++.h>
using namespace std;
int n;
char a[200005];
int ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ch[i]>>a[i];
	}
	int l=1,r=n,lastl=ch[1],lastr=ch[n];
	long long cn=0;
	while(l<r){
		if(lastl>lastr){
			if(a[l]!=a[r]){
			lastl-=lastr;
			r--;	
			cn+=lastr;
			lastr=ch[r];
			}else{
			lastl-=lastr;
			r--;
			lastr=ch[r];
			}
		}else{
			if(lastl<lastr){
			if(a[l]!=a[r]){
			lastr-=lastl;
			l++;	
			cn+=lastl;
			lastl=ch[l];
			}else{
			lastr-=lastl;
			l++;
			lastl=ch[l];
			}
			}else{
			if(a[l]!=a[r]){
			l++;	
			r--;
			cn+=lastl;
			lastl=ch[l];
			lastr=ch[r];
			}else{
			l++;	
			r--;
			lastl=ch[l];
			lastr=ch[r];
			}
			}
		}
	}
	cout<<cn;
	return 0;
}
