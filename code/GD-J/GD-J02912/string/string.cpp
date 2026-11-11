#include<iostream>
#include<vector>
using namespace std;
long long a[1000000+1];
char c[1000000+1]; 
long long cnt=0;
int n;
void sub(long long m, char c1, long long i, long long x){
	if(x==i) return;
	if(i==n-1) return;
	if(a[x]==0) sub(m, c1, i, x-1);
	if(c1==c[x]){
		if(m>a[x]){
			a[x]=0;a[i]=m-a[x];
			sub(m-a[x], c1, i, x-1);
		}else if(m==a[x]){
			a[x]=a[i]=0;
		}
		else {
			a[i]=0;a[x]-=m;
		}
	}
	else{
		if(m>a[x]){
			a[x]=0;a[i]=m-a[x];cnt+=a[x];
			sub(m-a[x], c1, i, x-1);
		}
		else if(m==a[x]){
			a[x]=a[i]=0; cnt+=m;
		}
		else {
			a[i]=0;a[x]-=m;cnt+=m;
		}
	}
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	cin >> n;
	string s="";
	for(int i = 0; i < n; i ++){
		cin >> a[i] >> c[i];
		
	}
	for(int i = 0; i < n; i++){
		if(a[i]==0)continue;
		sub(a[i],c[i],i, n-1-i);
	}
	cout << cnt; 
	fclose(stdin);
	fclose(stdout);
} 
