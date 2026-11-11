#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","w","stdout");
	int n;cin>>n;
	int m;cin>>m;
	int a[5005]={0};
	for(int i=0;i<n;i++) {cin>>a[i];}
	sort(a,a+n);

	int maxx=0;
	for(int line=a[0];line<=a[n-1];line++) {
		int line_cha[5005]={0};
		int line_cha_i=0;
		for(int i=0;i<n;i++) {
			if (a[i]<=line) {
				line_cha[line_cha_i]=line-a[i];
				line_cha_i+=1;
			}
		}
		sort(line_cha,line_cha+line_cha_i);
		int max=0;
		int line_m=m;
		for(int i=0;i<line_cha_i;i++) {
			if(line_m>=line_cha[i]) {
				line_m-=line_cha[i];
				max+=1;
			}
		}
		if (max>=maxx) {
			maxx=max;
		}
    }
    cout<<maxx;
    return 0;
}
