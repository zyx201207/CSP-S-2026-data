#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s = " ";
	long long n,len = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		long long nums;
		char c;
		cin>>nums>>c;
		for(int j = 1;j <= nums;j++){
			s = s + c;
		}
		len += nums;
	}
	long long cnt = 0,l = 1,r = len;
	while(l <= r){
		if(s[l] != s[r])cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	
	return 0;
} 
//估计有16分或者更低，总之是完蛋了 
/*
It seems that I will AFO after today.
Fortounatly （可能没拼对） I have entered a chemistry competition team in our school.
What a good news.
I'd like to play Genshin but I have to do my homework.What a bad news.
Genshin Impact UID:310217294  
Make Friends.
*/
