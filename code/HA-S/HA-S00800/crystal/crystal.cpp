#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;

long long n,m;

long long a[maxn];

int ans;

int cha,chanum;

int main(){
//记得删注释	

//好样的 我记住了 

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		
		if(i==2)cha=a[i]-a[i-1];
		
		if(i>=2&&a[i]-a[i-1]==cha){
			
			chanum++;
			
		}
		
	}
	/*真是给我区完了 看T1能看懂准备写正解
	    结果发现正解自己想不出来
		后来准备特判+暴力
		写暴力的时候突然发现自己分不清upperbound和lowerbound
		开了个测试的代码准备比较一下不同
		结果发现lowerbound和upperbound到底怎么写自己忘完了
		想写二分结果写炸了也不敢再改了只能删了
		最后写出来一大坨
		我是什么区啊
		都当区了 我甚至还不是区中最会蠕动的那种
		不管了 结束之后回家我会使用10.7权重的T80-UD发射芒果带走一些小朋友 
		或者游玩一些galgame
	*/
	
	sort(a+1,a+1+n);
	
	if(chanum==n-1){
		
		for(int i=1;i<n;i++){
			
			if(i*(1+i)*cha<=2*m)ans++;
				
			else break;
			
		}
		
		cout<<ans+1<<"\n";
		
		return 0;
		
	}else{
		
		for(int i=a[n];i>=a[1];i--){
			
			int maxnum;
			
			int numm=m;
			
			int ansnum=0;
			
			for(int j=n;j>=1;j--){
				
				if(a[j]<=i){
					
					maxnum=j;
					
					break;
					
				}
				
			}
			
			for(int k=maxnum;k>=1;k--){
				
				if(numm-(i-a[k])<0){
					
					break;
					
				}else{
					
					numm-=i-a[k];
					
					ansnum++;
					
				}
				
			}
			
			ans=max(ansnum,ans);
			
		}
		
		cout<<ans<<"\n";
		
	}
	/*
		学了一年多的OI OI确实会了一些了
		但这不是最大的收获
		我最大的收获是会玩galgame了，也会打战雷了，也许可喜可贺？ 
		
		bvvd商业兽性太明显了 线车虎H1何德何能和两线虎一个权重 
		还有8.7以上的车基本都升0.3权重但是UD和2s38不变？
		
		2s38补强一下可以理解 UD怎么回事
		bvvd眼里看豹2A4正面全绿的T-80-UD应该比豹2A4低0.3权重，真是牛大了
		无妨 我是玩UD的 我只需要享受版本红利就可以了 而别的玩家要考虑的就多了 
		*/ 
	
	return 0;
	
}
