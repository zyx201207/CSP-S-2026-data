//GZ-J00526 袁金厚 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,ans=0;
struct abc{
	long long num;
	char s;
};
abc m[200500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].num>>m[i].s;
	}

	long long x=1,y=n;
	while(y-x>=1){
		if(m[x].s!=m[y].s){
			if(m[x].num>m[y].num){
			ans=ans+m[y].num;

			m[x].num=m[x].num-m[y].num;
			y--;
			continue;
			}
			if(m[x].num<m[y].num){
			ans=ans+m[x].num;
			m[y].num=m[y].num-m[x].num;
			x++;
			continue;
			}
			if(m[x].num==m[y].num){
				ans=ans+m[x].num;
				x++;
				y--;
				continue;
			}	
		}
		else{
			if(m[x].num>m[y].num){
			m[x].num=m[x].num-m[y].num;
			y--;
			continue;	
			}
			if(m[x].num<m[y].num){
			m[y].num=m[y].num-m[x].num;
			x++;
			continue;
			}
			if(m[x].num==m[y].num){
				x++;
				y--;
				continue;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
