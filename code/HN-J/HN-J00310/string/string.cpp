//我是秦始皇，我还没有死，这道题目给我AC，我封你做AC大将军 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum;
int sum1,p1,cnt1;
struct Node{
	int a;
	char c;
}a[200001],a1[200001],a2[200001];
string s;
int l,r;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		sum+=a[i].a;
		if(a[i].c==a[i-1].c){
			n--;
			i--;
			a[i].a+=a[i+1].a;
		}
	}
	if(sum<=1e8){
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=a[i].a;j++){
				s=s+a[i].c;
			}
		}
		int ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=s[s.size()-i-1]){
				ans++;
			} 
		}
		cout<<ans/2;
	}else{
		for(int i=1;i<=n;i++){
			sum1+=a[i].a;
			if(sum1>=sum/2){
				sum1-=a[i].a;
				p1=i+1;
				a1[i].a=sum/2-sum1;
				a[i].a-=a1[i].a;
				a1[i].c=a[i].c;
				break;
			}
			a1[i].a=a[i].a;
			a1[i].c=a[i].c;
		}
		for(int i=p1;i<=n;i++){
			if(i==p1&&sum%2==1){
				a[i].a--;
				if(a[i].a==0){
					continue;
				}
			}
			a2[++cnt1].a=a[i].a;
			a2[cnt1].c=a[i].c;
		}
		reverse(a2+1,a2+cnt1+1);
		int s1=0,s2=0,ans=0;
		for(int pos1=0,pos2=0;pos1<p1&&pos2<=cnt1;){
			while(s1<s2){
				pos1++;
				s1+=a1[pos1].a;
				if(a1[pos1].c!=a2[pos2].c){
					if(s1>=s2){
						ans+=s2-(s1-a1[pos1].a);
					}else{
						ans+=a1[pos1].a;
					}
				}
			}
			if(pos2<=cnt1){
				pos2++,s2+=a2[pos2].a;
			}
			if(a1[pos1].c!=a2[pos2].c){
				ans+=s1-(s2-a2[pos2].a);
			}
			
		}
		cout<<ans<<endl; 
	//	for(int i=1;i<=p1-1;i++){
	//		cout<<a1[i].a<<a1[i].c<<endl;
	//	}
	//	cout<<"-----"<<endl;
	//	for(int i=1;i<=cnt1;i++){
	//		cout<<a2[i].a<<a2[i].c<<endl;
	//	}
	}
	return 0;
}

