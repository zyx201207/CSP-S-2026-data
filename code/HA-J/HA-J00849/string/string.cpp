#include<bits/stdc++.h>
using namespace std;
struct s{
	int num;
	char ch;
}a[2000005],b[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
		b[n-i+1].num=a[i].num;
		b[n-i+1].ch=a[i].ch;
		if(a[i].ch!=a[i-1].ch&&i!=1)flag=0;
	}
	if(flag)cout<<0;
	else{
		long long tot=0;
		for(int i=1;i<=n;i++){
			if(a[i].num==b[i].num&&a[i].ch!=b[i].ch)tot+=a[i].num;
			else if(a[i].num!=b[i].num&&a[i].ch!=b[i].ch){
				
				if(a[i].num>b[i].num){
					int m=a[i].num-b[i].num;
					int j=i+1;
					tot+=b[i].num;
					b[i].num=0;
					while(m>0){
						if(b[j].num>=m){
							if(b[j].ch!=a[i].ch)tot+=m;
							b[j].num-=m;
							m=0;
							break;
						}else if(b[j].num<m){
							if(b[j].ch!=a[i].ch)tot+=b[j].num;
							m-=b[j].num;
							b[j].num=0;
							j++;
						}
					}
				}if(a[i].num<b[i].num){
					int m=b[i].num-a[i].num;
					int j=i+1;
					tot+=a[i].num;
					a[i].num=0;
					while(m>0){
						if(a[j].num>=m){
							if(a[j].ch!=b[i].ch)tot+=m;
							a[j].num-=m;
							m=0;
							break;
						}else if(a[j].num<m){
							if(a[j].ch!=b[i].ch)tot+=a[j].num;
							m-=a[j].num;
							a[j].num=0;
							j++;
						}
					}
				}
			}
			else if(a[i].num!=b[i].num&&a[i].ch==b[i].ch){
				if(a[i].num>b[i].num){
					int m=a[i].num-b[i].num;
					int j=i+1;
					b[i].num=0;
					while(m>0){
						if(b[j].num>=m){
							if(b[j].ch!=a[i].ch)tot+=m;
							b[j].num-=m;
							m=0;
							break;
						}else if(b[j].num<m){
							if(b[j].ch!=a[i].ch)tot+=b[j].num;
							m-=b[j].num;
							b[j].num=0;
							j++;
						}
					}
				}if(a[i].num<b[i].num){
					int m=b[i].num-a[i].num;
					int j=i+1;
					a[i].num=0;
					while(m>0){
						if(a[j].num>=m){
							if(a[j].ch!=b[i].ch)tot+=m;
							a[j].num-=m;
							m=0;
							break;
						}else if(a[j].num<m){
							if(a[j].ch!=b[i].ch)tot+=a[j].num;
							m-=a[j].num;
							a[j].num=0;
							j++;
						}
					}
				}
			}
		}
		cout<<(tot/2);
	}
	return 0;
}   
                                