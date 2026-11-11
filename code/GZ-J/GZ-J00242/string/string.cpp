//GZ-J00242 北京师范大学贵阳附属中学 李培源
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long sum=0,ans=0;
struct node{
	int a;
	char c;
}b[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		sum+=b[i].a;
	}
	int i=1,j=n;
	long long q=0;
	while(q<sum/2&&i<=j){
//		cout<<q<<endl;
		if(b[i].c!=b[j].c){
			if(b[i].a==b[j].a){
				ans+=b[i].a;
				q+=b[i].a;
				i++,j--;
			}
			else if(b[i].a<b[j].a){
				ans+=b[i].a;
				q+=b[i].a;
				b[j].a-=b[i].a;
				i++;
			}
			else{
				ans+=b[j].a;
				q+=b[j].a;
				b[i].a-=b[j].a;
				j--;
			}
		}else{
			if(b[i].a==b[j].a){
				q+=b[i].a;
				i++,j--;
			}
			else if(b[i].a<b[j].a){
				q+=b[i].a;
				b[j].a-=b[i].a;
				i++;
			}
			else{
				q+=b[j].a;
				b[i].a-=b[j].a;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
