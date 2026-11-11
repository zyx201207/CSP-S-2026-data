//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e6+5;
//string s;
//int n;
//int cishu;
//struct node{
//	int count;
//	char alpha;
//}a[N];
//int ans;
//int huiwen(string str,int sta,int stb,int ans){
//	if(str.size()%2==0){
//		if(sta+1 == stb)return ans;
//	}
//	else if(str.size()%2==1){
//		if(sta+1 == stb-1 || sta == stb)return ans;
//	}
//	if(str[sta] == str[stb]){
//		huiwen(str,++sta,--stb,ans);
//	}
//	else{
//		string str1,str2;
//		str1=str;
//		str2=str;
//		str1[0]=str1[str.size()-1];
//		str2[str.size()-1]=str2[0];
//		int num1=huiwen(str1,++sta,--stb,++ans);
//		int num2=huiwen(str2,++sta,--stb,++ans);
//		ans+=min(num1,num2);
//	}
//}
//int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].count>>a[i].alpha;
//		for(int j=1;j<=a[i].count;j++){
//			s+=a[i].alpha;
//		}
//	} 
//	cout<<huiwen(s,0,s.size()-1,0);
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int n;
string s;
int ans;
struct node{
	int count;
	char alpha;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].count>>a[i].alpha;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].count;j++){
			s+=a[i].alpha;
		}
	}
	int i=0,j=s.size()-1;
	for(int k=0;k<=s.size()/2;k++){
		if(s[i]!=s[j])ans++;
		i++,j--;
	}
	cout<<ans;
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/

