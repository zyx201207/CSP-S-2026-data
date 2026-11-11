#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum=0;
struct node{
	long long len;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].len);
		cin>>a[i].c;
	}
	int l=1,r=n;
	long long lena=a[l].len,lenb=a[r].len;
	while(l!=r&&l<r){
		if(a[l].c!=a[r].c){
			if(lena>lenb){
				sum+=lenb;
				lena-=lenb;
				r--;
				lenb=a[r].len;
			}
			else if(lena<lenb){
				sum+=lena;
				lenb-=lena;
				l++;
				lena=a[l].len;
			}
			else if(lena==lenb){
				sum+=lena;
				l++;
				r--;
				lena=a[l].len;
				lenb=a[r].len;
			}
		}
		else if(a[l].c==a[r].c){
			if(lena<lenb){
				lenb-=lena;
				l++;
				lena=a[l].len;
			}
			else if(lena>lenb){
				lena-=lenb;
				r--;
				lenb=a[r].len;
			}
			else{
				l++;
				r--;
				lena=a[l].len;
				lenb=a[r].len;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}

