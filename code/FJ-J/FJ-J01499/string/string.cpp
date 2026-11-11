#include <bits/stdc++.h>
using namespace std;
int n;
double al,a2,cnt;
struct l{
	double ans;string s;string s1;string s2;
}a[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].ans>>a[i].s;
		a2+=a[i].ans;
	}
	al=(a2+1)/2;
	for(int i=al;i>=0;i--){
		a[al-i].s1=a[i].s;
	}
	for(int i=n;i>=al+1;i--){
		a[n-i].s2=a[i].s;
	}
	while(int i=0<al){
		if(a[i].s1==a[i].s2){
			cnt++;
		}
		i++;
	}
	cout<<a2-cnt;
	return 0;
}
