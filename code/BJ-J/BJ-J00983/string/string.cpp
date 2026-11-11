#include <bits/stdc++.h>
using namespace std;
struct k{
	long long begin;
	long long end;
};
char a1[100005] , a2[100005];
long long sum = 0 ;
k key1[100005] = {0};
k key2[100005] = {0};
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		long long nmn;
		char cn;
		cin >> nmn;
		cin >> cn;
		key1[i].begin = key1[i - 1].end + 1;
		key1[i].end = key1[i].begin + nmn - 1;
		a1[i] = cn;
		a2[n - i + 1] = cn;
	}
	for(int i = n;i >= 1;i--){
		key2[i].begin += key1[i].begin - key1[n - i + 1].end + key1[n - i + 1].begin;
		key2[i].end += key2[i].begin + key1[n - i + 1].end - key1[n - i + 1].begin;
	   }
	   long long pl = min(key1[1].end , key2[1].end);
	for(long long l = 1 , r = 1; l <= n && r <= n;){
		char man = 'l';
		if(key1[l].end > key2[r].end) man = 'r'; 
		else if(key1[l].end == key2[r].end) man = 'd';
		if(a1[l] == a2[r]){
			if(man == 'r'){r++;pl = min(key1[l].end , key2[r].end);}
			if(man == 'l'){l++;pl = min(key1[l].end , key2[r].end);}
			else{
				l++;
				r++;pl = min(key1[l].end , key2[r].end);
			}
			continue;
		}
		if(man == 'r') {sum += abs(pl - max(key1[l].begin , key2[r++].begin) + 1);pl = min(key1[l].end , key2[r].end);}
		else if (man == 'l'){sum += abs(pl - max(key1[l++].begin , key2[r].begin) + 1);pl = min(key1[l].end , key2[r].end);}
		else{
			sum += abs(pl - max(key1[l++].begin , key2[r++].begin) + 1);pl = min(key1[l].end , key2[r].end);
		}

		
	}
	cout << sum ;
	return 0;
}