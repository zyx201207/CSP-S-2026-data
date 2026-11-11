#include<bits/stdc++.h>
using namespace std;
long long s=0,m=0;
long long num;
char sy;
long long l[1000000]={0},d[1000000]={0};
void zx(int n){
	cin>>n;
	int i;
	for(i=1;i<=n;i++){
		cin>>num>>sy;
		s+=num;
		for(i=1;i<=num;i++){
			l[i]=sy;
		}
	}
	for(int j=s;j>=1;j--){
		d[++i]=l[j];
	}
     for(i=1;i<=s;i++){
     	if(l[i]==d[i]){
     		m++;
		 }
    }
    if(m==s){
    	cout<<"0";
	}
	else cout<<(s-m)/2;
	}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    zx(n);
	return 0;
}
