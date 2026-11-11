#include<bits/stdc++.h> 
using namespace std;

struct neirong{
	long long num;
	char zimu;
}a[200005];
int n; 
long long cnt;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].zimu;
	}
	int i=1,j=n;
	while(a[i].num!=0&&a[j].num!=0){
		//int len=(max(a[i].num,a[j].num)-min(a[i].num,a[j].num));
		int aa=a[i].zimu;
		int bb=a[j].zimu;
		if(aa!=bb){
			cnt+=min(a[i].num,a[j].num);
		}
		a[i].num-=min(a[i].num,a[j].num);
		a[j].num-=min(a[i].num,a[j].num);
		if(a[i].num==0){
			i++;
		}if(a[j].num==0){
			j--;
		}
	}
	cout<<cnt;
	return 0;
}
