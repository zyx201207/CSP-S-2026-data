#include<bits/stdc++.h>
using namespace std;
char a[200005];
char b[200005];
double mid;
int n;
long long num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long o=1;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		for(int i=1;i<=b[i]-'0';i++){
			a[o]=a[i];
			o++;
		}
		mid=b[i]-'0';
	}
	int mid1=ceil(mid/2);
	if(mid1==ceil(mid/2)){
		o=1;
		for(int i=mid1+1;i<=n;i++){
			if(a[i-o]!=a[i]){
				num+=2;
			}
			o++;
		}
	}
	else{
		for(int i=mid1+1;i<=n;i++){
			if(a[i-o-1]!=a[i]){
				num+=2;
			}
		}
	}
	cout<<num;
}
