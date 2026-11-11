#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s,l,r,sl,sr,m;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	r=n;
	sr=a[r];
	s=sr;
	while(sl+sr<=m){
		if(sl>sr){
			s+=(c[l]!=c[r])?(sl-sr):0;
			r--;
			sr+=a[r];
		}
		else{
			s+=(c[l]!=c[r])?(sr-sl):0;
			l++;
			sl+=a[l];
		}
	}
	cout<<s;
	return 0;
}
