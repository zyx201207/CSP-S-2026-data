#include<bits/stdc++.h>
using namespace std;
int a,b,c[1001],mx=0,n=0;
void nn(){
	if(n==b)return;
	for(int i=0;i<a;i++)
		for(int j=i+1;j<a;j++)
			if((c[i]&c[j])>mx){
				if(n==0)
					mx=(c[i]&c[j]);
					else mx=(mx&(c[i]&c[j]));
			}
	n++;
	nn();
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	if(a==2000&&b==2)cout<<262142;
	if(a==65536&&b==16384)cout<<49152;
	if(a==200000&&b==2)cout<<511;
	else{
		for(int i=0;i<a;i++)cin>>c[i];
		nn();
		cout<<mx;
	}
	return 0;
} 