//GZ-S00408
//王怡然
//毕节梁才学校 
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;//用LL 
LL a[500000+10];
LL s[500000+10];
int n;
LL m;//LL

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

//	freopen("crystal4.in","r",stdin);
//	freopen("mytest.out","w",stdout);	
	
	scanf("%d%lld",&n,&m);//lld
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);//lld
	
	int ma=-0x3f3f3f3f;//最多的个数（答案 
	
	sort(a+1,a+n+1);//排序 
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];//前缀和 
	
	for(int i=1;i<=n;i++){
		//二分 找最后一个满足添加数<=m的
		int l=1,r=i;//右边界应该是i i肯定符合要求 
		while(l<r){
			int mid=(l+r)/2;//无-1 无+1 
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ma=max(ma,i-r+1);
//		printf("%d\n",s[i]); 
	}
	
	printf("%d\n",ma);
	
	return 0;
}
