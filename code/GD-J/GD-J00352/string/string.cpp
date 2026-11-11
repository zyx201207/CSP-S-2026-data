#include<bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int i=1,j=n;
	int c,d;
	char e,f;
	bool o=true;
	long long co=0;
	while(o){
		c=a[i],d=a[j];
		e=b[i],f=b[j];
		if(c==d){
			if(e!=f){
				co+=c;
			}
			i++;
			j--;
		}else if(c>=d){
			if(e!=f){
				co+=d;
			}
			a[i]-=d;
			j--;
		}else if(d>=c){
			if(e!=f){
				co+=c;
			}
			a[j]-=c;
			i++;
		}
		if(i>=j) o=false;
	}
	cout<<co;
	return 0;
} 
