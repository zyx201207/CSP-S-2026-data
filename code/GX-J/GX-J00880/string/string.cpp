#include<bits/stdc++.h>
using namespace std;
int n;
string s;
//struct awa{
//	int x;
//	char c;
//}a[200010];
//int qwq(int )
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	// bu xiang xie le    emmm....dui
	/*
	cin>>n;
	long long sum;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		sum+=a[i].x;
	}
	long long su=sum/2;
	long long s=0;
	char mid='';
	int num=0;
	for(int i=1;i<=n;i++){
		s+=a[i].x;
		if(s>sum){
			mid=a[i].c;
			num=i-1;
		}
	}
	if(sum%2==1){
		a[num].x--;
	}
	int dy=sum-su;
	for(int i=su;i>=1;i--){
		
	}
	*/
	
	//bao li
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	int len=s.length();
	string s1="",s2="";
	int len1,len2;
	len1=len2=len/2;
	if(len%2==1){
		for(int i=0;i<=len/2;i++){
			s1[i]=s[i];
			s2[i]=s[i+(len/2)+1];
			//cout<<s1[i]<<" "<<s2[i]<<" "<<i+(len/2)+1<<endl;
		}
		//cout<<s1.length()<<" "<<s2.length()<<endl;
	}
	else{
		for(int i=0;i<=len/2-1;i++){
			s1[i]=s[i];
			s2[i]=s[i+(len/2)];
			//cout<<s1.size()<<" "<<s2.size()<<endl;
			//cout<<s1[i]<<" "<<s2[i]<<" "<<i+(len/2)<<endl;
		}
		/*
		for(int i=0;i<=len/2-1;i++){
			cout<<s1[i]<<" "<<s2[i]<<endl;;
		}
		*/
	}
	string s3;
	int j=0;
	//int len2=s2.size();
	//cout<<len2<<endl;
	for(int i=len2-1;i>=0;i--){
		s3[j]=s2[i];
		j++;
		//cout<<1<<endl;
	}
	/*
	for(int i=0;i<=len2-1;i++){
		cout<<1<<endl;
		cout<<s2[i]<<" "<<s3[i]<<endl;
	}
	*/
	//cout<<s2<<endl<<s3<<endl;
	int ans=0;
	for(int i=0;i<=len1-1;i++){
		if(s1[i]!=s3[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
