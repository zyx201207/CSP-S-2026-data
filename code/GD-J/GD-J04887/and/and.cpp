#include<bits/stdc++.h>
using namespace std;
int n,m;

struct node{
	int a;
	int sum ;// 1的总数
	int b; // 第一个1的出现位置 
};
node x[200001];
void aw(int s,int i){
	int cnt=0,fir;
	while(s!=0){
		cnt++;
		int si = s%2;
		s/=2;
		if(si == 1){
			x[i].b = cnt;
			x[i].sum++;
			
		}
	}
}
bool cmp(node a,node b){
	if(a.b == b.b){
		return a.sum > b.sum;
	}
	return a.b > b.b;
}
int awy(int num1,int num2){
	vector<int>s1;
	vector<int>s2;
	while(num1 != 0){
		s1.push_back(num1%2);
		num1/=2;
	}
	while(num2 != 0){
		s2.push_back(num2%2);
		num2/=2;
	}
	
	int sum=0;
	int len1 = s1.size();
	int len2 = s2.size();
	int min_len = min(len1,len2);
	vector<int>s3;
	if(len1 > len2){
		for(int i=1;i<=len1-len2;i++){
			s2.push_back(0);
		}
	}else{
		for(int i=1;i<=len2-len1;i++){
			s1.push_back(0);
		}
	}
	
	for(int i = 0; i < max(len1 , len2); i++){
		
		if(s1[i] == 1 && s2[i] == 1) s3.push_back(1);
		else s3.push_back(0);
		

	}

	
	for(int i = 0; i < max(len1 , len2); i++){
	
		sum += s3[i] * pow(2 , i );
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> x[i].a;
		aw(x[i].a,i);
	}
	sort(x + 1,x + n + 1,cmp);
	int ans=x[1].a;
	for(int i = 2; i <= m; i ++){
		ans = awy(ans,x[i].a);
	}
	cout<<ans;
	return 0;
}
