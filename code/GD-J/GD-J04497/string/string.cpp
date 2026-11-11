#include<bits/stdc++.h>
using namespace std;
/*bool cmp(string s){
	long long k = s.size();
	long long j = k - 1;
     if(k % 2){
     	for(int i = 0;i <= k / 2;i++){
     		if(s[i] != s[j]) return false;
     		j--;
		 }
	 }
	 else{
	 		for(int i = 0;i < k / 2;i++){
     		if(s[i] != s[j]) return false;
     		j--;
		 }
	 }
	 return true;
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n ,a;
     cin >> n;
	string s;
	char c;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
	   for(int j = 1;j <= a;j++){
	   	s += c;
	   }
}  
      
     /*if(cmp){
     	cout << 0;
     	return 0;
	 }*/
	 
	 long long sum = 0;
	 long long k = s.size();
	long long j = k - 1;
     if(k % 2){
     	for(int i = 0;i <= k / 2;i++){
     		if(s[i] != s[j]) sum++;
     		j--;
		 }
	 }
	 else{
	 		for(int i = 0;i < k / 2;i++){
     		if(s[i] != s[j]) sum++;
     		j--;
		 }
	 }
	 cout << sum;
	return 0;
} 

