#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005],c2[200005];
long long a[200005],ans,cnt,a2[200005];
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int ta;char tc;
		cin>>ta>>tc;
		c2[i]=tc;
		a2[i]=ta;
//		printf("%c %c %c",tc,c[cnt],cnt);
		if(tc==c[cnt]){
			a[cnt]+=ta;
		}
		else{
			a[++cnt]=ta,c[cnt]=tc;
		}
	}	
//	printf("%lld\n",cnt);
//	for(int i=1;i<=cnt;i++){
//		printf("%lld %c\n",a[i],c[i]);
//	}
//判断是否为回文串
	bool flag=true;
	for(int i=1,j=cnt;i<=cnt/2;i++,j--){
		if(c[i]!=c[j]||a[i]!=a[j]){
			flag=false;break;
		}
	} 
	if(flag){
		printf("0");
		return 0; 
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=a2[i];j++){
//			str+=c2[i];
//		}
//	}
//正解？算了暴力 
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=a[i];j++){
			str+=c[i];
		}
	}
//	cout<<str<<endl;
//	str="0"+str;
	for(int i=0,j=str.size()-1;i<=(str.size()-1)/2;i++,j--){
		if(str[i]!=str[j]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
6
1 a
3 c
1 b
2 c
1 c
1 a
回文串，通过 
正解？
3
2 a
2 b
1 c
aabbbc
for(int i=1,j=cnt;i<j;i++,j--){
		if(c[i]==c[j]){
			if(a[i]==a[j])continue;
			else if(a[i]>a[j]){
				a[i]-=a[j];
				i--;
			}
			else{
				a[j]-=a[i];
				j++;
			} 
		}
		else{
			if(a[i]==a[j]){
				ans+=a[i];
			}
			else if(a[i]>a[j]){
				long long t=a[j];
				while(t<a[i]&&j>i){
					t+=a[--j];
				}
				ans+=a[i];
				a[j]=t-a[i];
				if(a[j]!=0)j++;
			}
			else{
				long long t=a[i];
				while(t<a[j]&&i<j){
					t+=a[++i];
				}
				ans+=a[j];
				a[i]=t-a[j];
				if(a[i]!=0)i--;
			}
		}
	} 
*/

