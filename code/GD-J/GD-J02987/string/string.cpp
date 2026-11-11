#include<bits/stdc++.h>
using namespace std;

void strj(string s,int mid){//奇数长度 
	string lt,rt;
	long long sum=0;
	for(int i=0;i<mid;i++){
		lt+=s[i];
	}
	for(int i=(int)s.size()-1;i>mid;i--){
		rt+=s[i];
	}
	for(int i=0;i<min((int)lt.size(),(int)rt.size());i++){
		if(lt[i]!=rt[i])sum++;
	}
	cout<<sum;
}

void stro(string s,int mid){//偶数长度 
	string lt,rt;
	int sum=0;
	for(int i=0;i<=mid;i++){
		lt+=s[i];
	}
	for(int i=(int)s.size()-1;i>mid;i--){
		rt+=s[i];
	}
	for(int i=0;i<min((int)lt.size(),(int)rt.size());i++){
		if(lt[i]!=rt[i])sum++;
	}
	cout<<sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;cin>>n;
	string s;
	for(long long i=0;i<n;i++){
		long long x;cin>>x;
		char lt;cin>>lt;
		for(long long j=0;j<x;j++){
			s.push_back(lt);
		}
	}
	//cout<<s;
	if((long long)s.size()%2==1){
		int mid=((long long)s.size()-1)/2;
		strj(s,mid);
	}
	else{
		int mid=((long long)s.size()-2)/2;
		stro(s,mid);
	}
	return 0;
}
