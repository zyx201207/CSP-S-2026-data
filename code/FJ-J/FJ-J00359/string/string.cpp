#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i;
	long long s=0,a[200005],b=0,e;
	char c[200005];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i]>>c[i];
		b+=a[i];
	}
	i-=1;
	int d=0;
	if(b%2==0){
		e=b/2;
	}
	else{
		e=b/2;
	}
	for(long long j=0;j<e;j++){
		if(c[d]!=c[i]){
			s+=1;
		}
		if(a[d]!=0){
			a[d]-=1;
		}
		else{
			d+=1;
		}
		if(a[i]!=0){
			a[i]-=1;
		}
		else{
			i-=1;
		}
	}
	if(s<=e){
		cout<<s;
	}
	else{
		cout<<b-s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}