#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
pr a[200005];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].fi;
		char x;
		cin>>x;
		a[i].se=x-'a';
	}
	for(int l=1, r=n, flag=-1, x=0;l<r;){
		int ls=a[l].fi, rs=a[r].fi;
		if(flag==0) ls=x;
		if(flag==1) rs=x;
		if(ls<rs){
			x=rs-ls;
			s+=(a[l].se!=a[r].se)*ls;
			flag=1;
			l++;
		} 
		else if(ls==rs){
			x=rs-ls;
			s+=(a[l].se!=a[r].se)*ls;
			flag=-1;
			l++;
			r--;
		}
		else{
			x=ls-rs;
			s+=(a[l].se!=a[r].se)*rs;
			flag=0;
			r--;
		}
	}
	cout<<s;
	return 0;
}
/*
     L                  OOOOOOOO         V                       V   EEEEEEEEEEEEE
     L                 O        O         V                     V    E
     L                O          O         V                   V     E
     L               O            O         V                 V      E
     L               O            O          V               V       E
     L              O              O          V             V        E
     L              O              O           V           V         EEEEEEEEEE
     L              O              O            V         V          E
     L               O            O              V       V           E
     L               O           O                V     V            E
     L                O         O                  V   V             E
     L                 O       O                    V V              E
     LLLLLLLLLLLLL      OOOOOOO                      V               EEEEEEEEEEEEEEE
*/
