#include<bits/stdc++.h>
using namespace std;
struct p{
	long long num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a1;
	long long sum=0;
	char c1;
	a[0].num=0;
	a[0].num='?';
	int j=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a1>>c1;
		if(c1==a[j].c){
			a[j].num+=a1;
		}
		else{
			j++;
			a[j].c=c1;
			a[j].num=a1;
		}
	}
	int l=1,r=j;
	while(l<r){
		if(a[l].num!=a[r].num||a[l].c!=a[r].c){
			if(a[l].num==a[r].num){
				sum+=a[l].num;
				l++;
				r--;
			}
			else if(a[l].c==a[r].c && a[l].num!=a[r].num){
				if(a[l].num>a[r].num){
					a[l].num-=a[r].num;
					r--;
				}
				else{
					a[r].num-=a[l].num;
					l++;
				}
			}
			else{
				if(a[l].num>a[r].num){
					a[l].num-=a[r].num;
					sum+=a[r].num;
					r--;
				}
				else{
					a[r].num-=a[l].num;
					sum+=a[l].num;
					l++;
				}
			}
		}
		else{
			l++;
			r--;
		}
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
