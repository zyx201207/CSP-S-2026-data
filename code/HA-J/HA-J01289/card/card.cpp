#include<bits/stdc++.h>
using namespace std;
//废弃 
//思路:检测左侧与右侧的不同数即可
//这个思路真是妙! !!!
int a[200005][2],n;
int b[100005][2],c[100005][2],bi=1,ct=1,ct2,ani,lani,bbi,cci;
char tmp;
bool ss,uss;
//只不过如何知道左和右?cnt?会超long long吗? 
long long cnt,mid,cnt1,ans,bcnt,ccnt;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	//事已至此先写个输入吧,目前不知道如何区分左右 
	scanf("%d",&n);
	//写输入的时候想到了天才想法!对折,对折成2个数组!比对即可!!!!
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i][0],&tmp);
		a[i][1]=tmp;
		cnt+=a[i][0];
	}
	//开始对折 !!!!
	if(cnt%2==0){
		mid=cnt/2;
		ss=1;
	}else{
		mid=(cnt-1)/2+1;
	}
	//左边 
	for(int i=1;;i++){
		cnt1+=a[i][0];
		if((!ss&&(cnt1>=mid))||(ss&&(cnt1>mid))){
			cnt1-=a[i][0];
			break;
		}
		b[i][0]=a[i][0];
		b[i][1]=a[i][1];
		bi++;
	}
	//中间处理
	 if(cnt1<mid){
	 	b[bi][0]=mid-cnt1-1;
	 	b[bi][1]=a[bi][1]; 
	 }
	//右边
	for(int i=n;i>=bi;i--){
		c[ct][0]=a[i][0];
		c[ct][1]=a[i][1];
		ct++;
		ct2=i;
	}
	//中间处理
	 if(cnt1<mid){
	 	c[ct][0]=a[bi][0]-(mid-cnt1-1)-1;
	 	c[ct][1]=a[bi][1];
	 }
	 //debug代码 （10个数据以内小测试） 
//	printf("bi:%d mid:%lld cnt:%lld cnt1:%lld bc:%d ct:%d ct2:%d",bi,mid,cnt,cnt1,a[bi][0]-(mid-cnt1),ct,ct2);
//	for(int i=1;i<=5;i++){
//		printf("\nb  %d:[0]%d[1]%d",i,b[i][0],b[i][1]);
//	}
//	for(int i=1;i<=5;i++){
//		printf("\nc  %d:[0]%d[1]%d",i,c[i][0],c[i][1]);
//	}
//	printf("\n");
//	for(int i=1;i<=5;i++){
//		for(int j=0;j<b[i][0];j++){
//			printf("%d ",b[i][1]);
//		}
//	}
//	printf("\n");
//	for(int i=1;i<=5;i++){
//		for(int j=0;j<c[i][0];j++){
//			printf("%d ",c[i][1]);
//		}
//	}
	//10:19成功完成数据的输入和处理!!!!!!!!!!!!!!!!!!!
	//计算&输出结果 
	while(1){
		if(bcnt==ccnt&&bcnt==mid-1)break;
		if(bcnt==ccnt){
			bbi++;
			bcnt+=b[bbi][0];
			cci++;
			ccnt+=c[cci][0];
		}else if(bcnt>ccnt){
			cci++;
			ccnt+=c[cci][0];
		}else{
			bbi++;
			bcnt+=b[bbi][0];
		}
		ani=min(bcnt,ccnt);
		if(b[bbi][1]!=c[cci][1]){
			ans+=ani-lani;
		}
		lani=ani;
	}
	printf("%lld",ans);
//	debug到11:23错误一大堆,我真服了 
// 11:36骗了3题一堆分,我感觉我又行了 
	return 0;
}
