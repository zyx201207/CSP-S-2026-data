#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,a[N],bj,cnt;
char c[N],tmp;
//bj的意思是上一次还有多少个没有配对,tmp是上一次配对的字符 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int i=1,j=n;
    while(i<=j){
    	if(c[i]==c[j]){
    		if(a[i]>a[j])a[i]-=a[j],j--;
    		else if(a[i]==a[j])a[i]=a[j]=0,i++,j--;
    		else if(a[i]<a[j])a[j]-=a[i],i++;
		}else{
			if(a[i]>a[j])a[i]-=a[j],cnt+=a[j],j--;
    		else if(a[i]==a[j])cnt+=a[j],a[i]=a[j]=0,i++,j--;
    		else if(a[i]<a[j])a[j]-=a[i],cnt+=a[i],i++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
//wok别搞这是T2
//感觉有点思路了，加油
//首先，绝对不可能把两端的字符都修改
//从数据表能得到，这是一道数学思维题
//双指针？ 
//首尾配对，如果相同，就 
//神了时间是14：28 
//卧槽大样例过不去！！！ 
//想到一个暴力的做法
//update:打个什么的暴力啊，只是随便加了个else 直接过大样例 
//我去过了！！！！！！！！！！！！！！！！！
//太开心了 
//9:30通过T2
//xju love ltc 
