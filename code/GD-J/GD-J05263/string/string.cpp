#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000001],b[100000001],t1,ans,cnt;
char c[100000001];
string s1,s2,s3;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cnt=0;
	int minn=0;
	t1=1;//特殊分 
	
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(i==0)minn=a[i];
		if(minn>a[i])minn=a[i];
		
		b[i]=a[i];
		if(a[i]!=1)t1=0;
	}
	if(sum%2==0){
		for(int i = 0;i<n;i++){
			for(int j=0;j<a[i];j++){
				s3+=c[i];
			}
		}
		int k1=sum/2;//数组的一半、回文点 
		for(int i=0;i<k1;i++){
			s1+=s3[i];
		}
		for(int i=sum;i>=k1;i--){
			s2+=s3[i];
		}
		for(int i=0;i<k1;i++){
			if(s1[i]!=s2[i])cnt++;
		} 
		cout<<cnt;
		return 0;
	}
	if(sum%2!=0){
		for(int i = 0;i<n;i++){
			for(int j=0;j<a[i];j++){
				s3+=c[i];
			}
		}
		int k1=sum/2;//数组的一半、回文点 
		for(int i=0;i<k1;i++){
			s1+=s3[i];
		}
		//cout<<"s1:"<<s1;
		for(int i=sum-1;i>k1;i--){
			s2+=s3[i];
		}
		//cout<<"s2:"<<s2;
		for(int i=0;i<k1;i++){
			if(s1[i]!=s2[i])cnt++;
		} 
		cout<<cnt;
		return 0;
	}	
	
	return 0;
}


