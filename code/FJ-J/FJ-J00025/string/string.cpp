#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum=0,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum=sum/2;
	int li=1,l=1,r=1,ri=n;
	while(true){
		if(li>=ri)break;
		if(c[li]==c[ri]){
			if(a[li]-l<a[ri]-r){
				r+=a[li]-l+1;
				li++;
				l=1;
			}else if(a[li]-l==a[ri]-r){
				li++;
				l=1;
				ri--;
				r=1;
			}else{
				l+=a[ri]-r+1;
				ri--;
				r=1;
			}
		}else{
			if(a[li]-l<a[ri]-r){
				ans+=a[li]-l+1;
				r+=a[li]-l+1;
				li++;
				l=1;
			}else if(a[li]-l==a[ri]-r){
				ans+=a[li]-l+1;
				li++;
				l=1;
				ri--;
				r=1;
			}else{
				ans+=a[ri]-r+1;
				l+=a[ri]-r+1;
				ri--;
				r=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
CCF你这T2咋么码量第1啊？
第一眼打算拼起来进行判断，但a[i]<=1e9
于是从两侧分别判断，但写的shi，具体参考代码
应该是O(n)的
//freopen
feropen
freopen("string.out","r",stdin);
freopen("string.ans","w",stdout);
freopen("string.in","r",stdin);
CCF CCF CCF CCF CCF CCF CCF CCF CCF CCF 
(认真诈骗ing)
*/ 
