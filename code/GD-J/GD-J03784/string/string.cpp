#include <bits/stdc++.h>
using namespace std;
const int N=2e5+15;
struct node{
	int n;
	char c;
}a[N],b[N];
long long ans=0,sum=0,s1=0;
bool c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].n);
		cin>>a[i].c;
		b[n-i+1].n=a[i].n;
		b[n-i+1].c=a[i].c;
		sum+=a[i].n;
	}
	int i=1,j=1;
	while(s1<sum){
		if(a[i].c!=b[j].c){
			if(a[i].n==b[j].n){
				ans+=a[i].n;
				b[j].c=a[i].c;
				s1=s1+b[j].n*2;
				i++,j++;
			}
			else if(a[i].n>b[j].n){
				ans+=b[j].n;
				s1=s1+(b[j].n*2); 
				b[j].c=a[i].c;
				a[i].n-=b[j].n;
				j++;
			}
			else if(a[i].n<b[j].n){
				ans+=a[i].n;
				s1=s1+(a[i].n*2); 
				a[i].c=b[j].c;
				b[j].n-=a[i].n;
				i++;
			}
		}
		if(a[i].c==b[j].c){
			if(a[i].n==b[j].n)i++,j++,s1=s1+a[i].n*2;
			else if(a[i].n>b[j].n){
				s1=s1+b[j].n*2;
				a[i].n-=b[j].n;
				j++;
			}
			else if(a[i].n<b[j].n){
				s1=s1+a[i].n*2;
				b[j].n-=a[i].n;
				i++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
