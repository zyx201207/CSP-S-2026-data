#include<bits/stdc++.h>
using namespace std;
struct nb{
	int a;
	char c;
}b[200002];
string x,y;
char aaa[1000001];
long long cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].a >>b[i].c ;
		cnt+=b[i]. a;
	}
	cnt/=2;
	int cnt2=0;
	for(int i=1;i<=n;i++){
		if(cnt2==cnt)break;
		for(int j=1;j<=b[i].a;j++){
			if(cnt2==cnt)break;
			cnt2+=1;
			x+=b[i].c ;
		}
	}
	cnt2=0;
	for(int i=n;i>=1;i--){
		if(cnt2==cnt)break;
		for(int j=1;j<=b[i].a;j++){
			if(cnt2==cnt)break;
			cnt2+=1;
			y+=b[i].c ;
		}
	}
	for(int i=0;i<cnt;i++){
		if(x[i]!=y[i])ans+=1;
	}
	cout<<ans;
	return 0;
}
//
//
//
//
//
//
//#include<bits/stdc++.h>
//#define l long long
//using namespace std;
//struct nb{
//	int a;
//	char c;
//}b[200002];
//l cnt,ans;
//l aaa[500]
//int main(){
////	freopen("string.in","r",stdin);
////	freopen("string.out","w",stdout);
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>b[i].a >>b[i].c ;
//		cnt+=b[i]. a;
//	}
//	cnt/=2;
//	while()
//}
//
//
//

