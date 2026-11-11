#include<bits/stdc++.h>
using namespace std;
struct S{
	long long n;
	char s;  
};
S m[200350],a[100350],b[100350];
long long n,cntl,ans,da[100350],db[100350];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>m[i].n>>m[i].s;
		cntl+=m[i].n;//计算字符串总长度 
		if(i>1 && m[i].s!=m[i-1].s) f=false;
	}//输入 
	if(f){
		cout<<0;
		return 0;
	}
	long long mid=cntl/2,cnt=0;
	for(int i=1;i<=n;i++){
		a[i].s=m[i].s;
		cnt+=m[i].n;
		if(cnt>mid){
			a[i].n=mid-(cnt-m[i].n);
			da[i+1]=da[i]+a[i].n;
			break;
		}
		else a[i].n+=m[i].n;
		da[i+1]=da[i]+a[i].n;
	} //截取前半段 
	cnt=0;
	for(int i=1;i<=n;i++){
		b[i].s=m[n-i+1].s;
		cnt+=m[n-i+1].n;
		if(cnt>mid){
			b[i].n=mid-(cnt-m[i].n);
			db[i+1]=db[i]+b[i].n;
			break;
		}	
		else b[i].n+=m[n-i+1].n;
		db[i+1]=db[i]+b[i].n;
	} //截取后半段
	
//	for(int i=1;i<=n;i++) cout<<m[i].n<<" "<<m[i].s<<endl;
//	for(int i=1;i<=1;i++) cout<<a[i].n<<" "<<a[i].s<<endl;
//	for(int i=1;i<=2;i++) cout<<b[i].n<<" "<<b[i].s<<endl;
//	cout<<mid;
//	for(int i=1;i<=n;i++){
//		cout<<da[i]<<" "<<db[i]<<endl;
//	}

	long long i=0,cnta=1,cntb=1;
	while(i<mid){
		//跳跃
		long long la=a[cnta].n+da[cnta],lb=b[cntb].n+db[cntb];
		if(a[cnta].s==b[cntb].s){
			if(la>lb){
				cntb++;
				i=lb; 
			}
			else{
				cnta++;
				i=la;
			} 
		} 
		//处理 
		else if(a[cnta].s!=b[cntb].s){
			ans+=la-i;
			i=la;
		}
//		cout<<i<<" "<<la<<" "<<lb<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

/*  ans=0+(a[cnta].n+da[cnta]-i)+(a[cnta].n+da[cnta]-i)=2
    da{0,2}    db{0,1,3}
  	aabb a abba
   	a{(2   ,  a)(2   ,  b)}
  	b{(1,a)(2   ,  b)(1,a)}
    cnta=3 fa=f cntb=3 fb=f
    i=1  跳跃->       1   更新->       2      跳跃->        3         更新->        4(停止循环) 
    (b[cntb].n+db[cntb]) (a[cnta].n+da[cnta]) (b[cntb].n+db[cntb]) (a[cnta].n+da[cnta])
*/	

