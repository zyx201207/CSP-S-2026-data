#include<bits/stdc++.h> 

using namespace std;

const int N=20000000; 


int n;//haoumany
int res=0;//step
int snum[N][4];//存下每个Ai的数量，以及ASC码表 
int L=0;//总长 
int sor[N];//数量 
int x=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;//组数 
	for(int i=1;i<=n;i++){
		int num;
		char alpha;
		scanf("%d %c",&num,&alpha);
		snum[i][1]=num;
		snum[i][2]=int(alpha);//存入
		L+=num; 
		sor[i]=num;
	} 
	
	//查找
	for(int i=1;i<=n/2;i++){//制造一般便可 
		int num;
		int alpha;
		num=snum[i][1];
		alpha=snum[i][2];
		for(int j=1;j<=num;j++){
			//拷入，开始进行判断
			//j:第几个Ai 
			int s_i;
			s_i=L+1-j;//对应第几个
			//在sor中找
			int searchx=1;
			while(s_i>sor[searchx]){
				s_i-=sor[searchx++];
			} 
			int number_d=snum[searchx][2];//找到了！
			//比较，不通则res++
			if(number_d!=alpha){
				res++;
			}
		}
	} 
	
	
	printf("%d\n",res);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
