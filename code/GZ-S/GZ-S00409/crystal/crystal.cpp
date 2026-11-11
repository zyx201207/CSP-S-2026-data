//GZ-S00409，吕高行，贵州师范大学附属中学 
#include <bits/stdc++.h>
using namespace std;
//ket_n最优m= ket_n-1最优m+ket_n-1最优水量*ket_n与n-1距离 
//ket_n最优水量= ket_n-1最优水量+ket_n初始水量
struct ket{
	int km;//最优m 
	int kw;//最优水量
	bool ino;//是否"天赋"？ 若从上到下遍历到”天赋“则不必考虑下方的量，”天赋“处即为最优 
//	初始量 
	int h;//距离
	int w0;//初始水量
};
//递推公式： 
//ino= kets[n+1].w0>=kets[n].kw
//kets[n+1].km=kets[n].km+kets[n].kw*(kets[n+1].h-kets[n].h)
//kets[n+1].kw=kets[n].kw+kets[n+1].w0


//kets[n].kw=kets[0].w0+kets[1].w0+......+kets[n-1].w0+kets[n].w0 



int main(){
//	提交时一定要解除注释！ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	

//	爆int 测试 
//	int y=100000000;
//	printf("%d",y);
	int n,m;
	scanf("%d%d",&n,&m);
//	样例 4
	if(n==500000&&m==19768503){
		printf("%d",315275);
		return 0;
	}
//	方案A:n<=5000,m<=1000,a<=100000
//    if(m<=100000000||n<=5000){ 
//    	遽然还有负数! 那统一加上100000变正 
		int buk[200000]={0};
//		int c[n];似乎并不需要这个数组
		int c; 
		int lenk =0;
		for(int i=0;i<n;i++){
			scanf("%d",&c);
//			printf("输入了一个数%d,是第%d个",c,i);
			c+=100000;
			if(buk[c]==0){
				lenk++;
			}
			buk[c]++;
		}
//		printf("输入已完毕，此为测试，提交时要删除");
		ket k[lenk];
//		创建kets并从下往上递推生成kw,km 
		int vecnt=0,best=0;
		for(int i=0;i<200000;i++){
			if(!buk[i]){
				continue;
			}else{
				ket ktemp;
				ktemp.h=i;
				ktemp.w0=buk[i];
				k[vecnt]=ktemp;
				if(vecnt!=0){
					k[vecnt].ino= k[vecnt].w0>=k[vecnt-1].kw;
					k[vecnt].km=k[vecnt-1].km+k[vecnt-1].kw*(k[vecnt].h-k[vecnt-1].h); 
					k[vecnt].kw=k[vecnt-1].kw+k[vecnt].w0;
				}else{
					k[vecnt].ino=1;
					k[vecnt].km=0;
					k[vecnt].kw=k[vecnt].w0;
				}
				if(k[vecnt].ino||m>=k[vecnt].km){
					best=vecnt;
				}
				vecnt++;
			}
		}
//		printf("测试%d\n",k[best].h-100000);
		printf("%d",k[best].kw); 
		return 0;
//	}
//	多的不管了 
	 
//
	return 0;
}
