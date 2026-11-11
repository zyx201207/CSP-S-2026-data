#include<bits/stdc++.h>
using namespace std;
const int N=200000+5;
int n,a[N],l,r,s1,s2;
long long cnt,sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	s1=1,s2=n;
	for(int i=1;i<=sum/2;i++){
		l++;
		r++;
		if(l>a[s1]){
			l=1;
			s1++;
		}
		if(r>a[s2]){
			r=1;
			s2--;
		}
		if(c[s1]!=c[s2])cnt++;
	}
	cout<<cnt;
	return 0;
}
