#include<bits/stdc++.h>
using namespace std;

int n,m,sum_and;
struct L{
	int num,num_1;
}a[200010];

bool cmp(L x,L y){
	if(x.num_1!=y.num_1) return x.num_1>y.num_1;
	else return x.num>y.num;
}

int main(){
	freopen("and.in","in",stdin);
	freopen("and.out","out",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].num);
		int temp=a[i].num;
		while(temp!=0){
			if(temp%2==1) a[i].num_1++;
			temp/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	sum_and=a[1].num;
	for(int i=2;i<=m;i++) sum_and=sum_and&a[i].num;
	printf("%d",sum_and);
	return 0;
}
