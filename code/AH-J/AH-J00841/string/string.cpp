#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a[200005],a1[200005],a2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,len,flag=0;
	cin>>n;
	string s;
	char c;
	int m=n;
	while(m--){
		scanf("%lld %c",&len,&c);
		sum+=len;
		a[flag++]=len;
		s+=c;
	}
	long long ans=0;
	long long len1=0;
	for(int i=0;len1<sum/2;i++){
		if(len1+a[i]<=sum/2){
			s1+=s[i];
			a1[i]=a[i];
			len1+=a[i];
		}else if(len1>=sum/2){
			break;
		}else if(len1+a[i]>sum/2){
			s1+=s[i];
			a1[i]=sum/2-len1;
			len1+=a1[i];
		}
	}
	flag=0;
	long long len2=0;
	for(int i=n-1;len2<sum/2&&i>0;i--){
		if(len2+a[i]<=sum/2){
			s2+=s[i];
			a2[flag++]=a[i];
			len2+=a[i];
		}else if(len2>=sum/2){
			break;
		}else if(len2+a[i]>sum/2){
			s2+=s[i];
			a2[flag++]=sum/2-len2;
			len2+=a2[i];
		}
	}
	int flag1=0,flag2=0;
	for(int i=0;flag1<s1.size()&&flag2<s2.size();i++){
		if(s1[flag1]!=s2[flag2]){
			if(a1[flag1]>a2[flag2]){
				ans+=a2[flag2];
				a1[flag1]-=a2[flag2];
				flag2++;
			}else if(a1[flag1]==a2[flag2]){
				ans+=a2[flag2];
				flag1++;
				flag2++;
			}else if(a1[flag1]<a2[flag2]){
				ans+=a1[flag1];
				a2[flag2]-=a1[flag1];
				flag1++;
			}
		}else{
			if(a1[flag1]>a2[flag2]){
				a1[flag1]-=a2[flag2];
				flag2++;
			}else if(a1[flag1]==a2[flag2]){
				flag1++;
				flag2++;
			}else{
				a2[flag2]-=a1[flag1];
				flag1++;
			}
		}
	}
	cout<<ans;
	return 0;
}
