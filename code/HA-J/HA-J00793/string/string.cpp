#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct strig{
	int num;
	char word;
}s[200005],s1[100005],s2[100005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].num>>s[i].word;
		sum+=s[i].num;
	}
	int flag=0;
	int sa=1,sb=1;
	for(int i=1;i<=n;i++){
		if(s[i].num+flag<=sum/2){
			s1[sa].num=s[i].num;
			s1[sa].word=s[i].word;
			sa++;
			flag+=s[i].num;
		}else if(s[i].num+flag>sum/2){
			s1[sa].num=sum/2-flag;
			s1[sa].word=s[i].word;
			if(sum%2!=0) s1[sa].num++;
			break;
		}
	}
	flag=0;
	for(int i=n;i>=1;i--){
		if(s[i].num+flag<=sum/2){
			s2[sb].num=s[i].num;
			s2[sb].word=s[i].word;
			sb++;
			flag+=s[i].num;
		}else if(s[i].num+flag>sum/2){
			s2[sb].num=sum/2-flag;
			s2[sb].word=s[i].word;
			break;
		}
	}
	int ans=0,a=1,b=1;
	for(int i=1;i<=n;i++){
		if(s1[a].word!=s2[b].word){
			ans+=min(s1[a].num,s2[b].num);	
		}
		if(s1[a].num>s2[b].num){
				s1[a].num-=s2[b].num;
				b++;
			}else if(s1[a].num<s2[b].num){
				s2[b].num-=s1[a].num;
				a++;
			}else if(s1[a].num==s2[b].num){
				a++;
				b++;
			}
	}
	cout<<ans;
	return 0;
}
