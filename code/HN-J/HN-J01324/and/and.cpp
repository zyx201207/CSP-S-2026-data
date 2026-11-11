#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+4;
int n,m;
bitset<31> b[N];
vector<int> js;

/*
4 2
3 15 12 12

0011
1111
1100
1100

12

5 3
31 3 1 15 7
10
11111 -- 31
00011 -- 3
00001 -- 1
01111 -- 15
00111 -- 7

7 
*/

void print(bitset<31> x){
	long long res = 0;
	long long wp = 1;
	for(int i = 0;i <= 30;i++,wp<<=1){
		if(x[i]){
			res += wp;
		}
	}
	cout << res;
}

bitset<31> apple(int depth){
	if(depth < 0){
		bitset<31> a;
		a = b[js[0]];
		for(int j = 1;j < js.size();j++){
			a = a&b[js[j]];
		}
		return a;
	}
	
	/*cout << depth << endl;
	for(int k = 0;k < js.size();k++){
		cout << js[k] << " ";
	}cout << endl;*/
	
	if(js.size() == m){
		bitset<31> a;
		a = b[js[0]];
		for(int j = 1;j < js.size();j++){
			a = a&b[js[j]];
		}
		return a;
	}
	if(js.size() > m){
		vector<int> js1;
		for(int j = 0;j < js.size();j++){
			if(b[js[j]][depth]){
				js1.push_back(js[j]);
			}
		}
		/*for(int k = 0;k < js1.size();k++){
			cout << js1[k] << " ";
		}cout << endl;*/
		if(js1.size() >= m){
			js = js1;
			return apple(depth-1);
		}else{
			return apple(depth-1);
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		long long x;
		cin >> x;
		b[i] = x;
	}
	/*
	
5 3
31 3 1 15 7
10
11111 -- 31
00011 -- 3
00001 -- 1
01111 -- 15
00111 -- 7
	*/
	for(int i = 30;i >= 0;i--){
		vector<int> js1;
		
		for(int j = 1;j <= n;j++){
			if(b[j][i]){
				js1.push_back(j);
			}
		}
		int ll = js1.size();
		//cout << js.size() << endl;
		if(js1.size() >= m){
			js = js1;
			bitset<31> res = apple(i-1);
			//cout <<res << " = ";
			print(res);
			break;
		}
	}
	return 0;
}
