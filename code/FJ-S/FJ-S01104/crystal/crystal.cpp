#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
void shuru(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);//输入数据+排序 
	for(long long i=0;i<n&&m>0;i++){//从下标0开始执行到n并且操作次数还有剩余 
        //cout<<i<<" "<<m<<endl;
		if(a[i]<a[i+1]){//比下一个数小
		    if(m>=(a[i+1]-a[i])) // 次数还够用
			for(long long j=i;j>=0&&m>=(a[i+1]-a[i]);j--){
			    m-=(a[i+1]-a[i]);//减去使用的次数 
			    a[j]=a[i+1];//加上这个值
			} else break;
		}else i++; //等于下一个数
	}
	for(int i=1;i<n;i++) 
	    if(a[i]==a[i-1]) ans++;//和上一个相等ans+1
	cout<<ans; 
	return 0;
}
