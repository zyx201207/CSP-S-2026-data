#include<bits/stdc++.h >
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,nh;
	cin>>n>>nh;
	long long a[n];
	for(long long e=0;e<n;e++){
		cin>>a[e];
	}
	int pkm=0;
	for(long long u=0;u<n;u++){
		string s="0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",d="0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",m="0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		int ak=0;
		int e=a[u],l=98;
		while(e!=0){
			if(e%2==1){
				s[l]='1';
			}
			e=e/2;
			l--;
		}
		for(long long h=u+1;h<n;h++){
			int o=98,k=a[h];
			while(k!=0){
			if(k%2==1){
				d[o]='1';
			}
			k=k/2;
			o--;
		}
		for(long long po=98;po>0;po--){
			if(s[po]=='1'&&d[po]=='1'){
				m[po]='1';
			}
			else if(s[po]=='0'&&d[po]=='0'){
				break;
			}
		}
		}
		int h=0;
		for(int y=98;y>=0;y--){
			if(m[y]=='1'){
				int mj=1;
				if(h==1){
					mj=2;
				}
				else if(mj!=0){
					for(int uzi=0;uzi<h;uzi++){
						mj=mj*2;
					}
				}
				ak=ak+mj;
			}
			h++;
		}
		if(ak>pkm){
			pkm=ak;
		}
	}
	cout<<pkm;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
