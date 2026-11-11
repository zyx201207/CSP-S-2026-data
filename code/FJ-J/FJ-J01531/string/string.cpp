#include<bits/stdc++.h>
using namespace std;
//struct ch{
//	long long cnt;
//	char c;
//};
//ch a[200005];
//ch b[200005];
//ch c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//long long n,cnt=0;
//cin>>n;
//for(int i=0;i<n;i++){
//	cin>>a[i].cnt>>a[i].c;
//	cnt+=a[i].cnt;
//}
////cout<<cnt<<endl;//
//cnt=(cnt+1)/2;
//long long cnt1=0,idx=0;
//for(int i=0;i<n;i++){
//	if(cnt1<cnt){
//		cnt1+=a[i].cnt;
//		b[i].c=a[i].c;
//		b[i].cnt+=a[i].cnt;
//	}else{
////		cout<<cnt1<<" "<<cnt<<" "<<i-1<<endl;//
//		idx=i-1;
//		if(cnt1>cnt){
//			b[i-1].cnt-=(cnt1-cnt);
//			c[i-1].cnt-=(cnt1-cnt);
//			cnt1-=(cnt1-cnt);
//		}
//		break;
//	}
//}
//for(int i=idx;i<n;i++){
//	c[i].c=a[i].c;
//	c[i].cnt+=a[i].cnt;
//}
//long long i=idx,j=idx,ans;
//while(i>=0 && j<n){
//	if(b[i].c==c[i].c){
//		if(b[i].cnt<c[i].cnt){
//			ans+=abs(b[i].cnt-c[i].cnt);
//		}else if(b[i].cnt>c[i].cnt){
//			ans+=abs(b[i].cnt-c[i].cnt);
//		}
//	}else{
//		ans+=abs(b[i].cnt-c[i].cnt);
//	}
//	i--;
//	j++;
//}
//cout<<ans;
//cout<<cnt1<<" "<<cnt<<" ";
//for(int i=0;i<n;i++){
//	while(b[i].cnt--){
//		cout<<b[i].c;
//	}
//}


	long long n;
	string str="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		while(a--){
			str+=c;
		}
	}
	long long len=str.length();
	string str1="";
	for(long long i=(len+1)/2-1;i>=0;i--){
		str1+=str[i];
	}
	long long cnt=0;
	for(long long i=(len+1)/2-1;i<len;i++){
		if(str1[i-((len+1)/2-1)]!=str[i]){
			cnt++;
		}
	}
	cout<<cnt;
return 0;
}
