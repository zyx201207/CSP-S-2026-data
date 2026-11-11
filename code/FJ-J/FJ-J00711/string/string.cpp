#include<bits/stdc++.h>
using namespace std;
const int MAX_INT  = 10e6;
struct com{
	int a;
	char c;
};
com data[MAX_INT];
com m[MAX_INT],W[MAX_INT];
com p[MAX_INT];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> data[i].a;
		cin >> data[i].c;
	}
	if(n%2 == 1){
		int cou = n/2+1;
		for(int i = 1;i <= n;i++){
			cou -= data[i].a;
			if(cou <= 0){
				data[i].a--;
				n--;
				break;
			}
		}
	}
	int half = n/2;
	int use = half;
	int uk;
	char reuse;
	bool f =true;
	int i = 1;
	while(f){
		if(use >= data[i].a){
			m[i].a = data[i].a;
			m[i].c = data[i].c;
			use -= m[i].a;
			i++;
		}else{
			m[i].a = use;
			m[i].c = data[i].c;
			uk = data[i].a-use;
			reuse = data[i].c;
			f = false;
		}
	}
    int use2 = half,nice = 0;
    bool g =true;
    int i2 = 1;
	if(uk!= 0){
		W[1].c = reuse;
		W[1].a = uk;
		nice = 1;
		use2 -= uk;
	}
	while(g){
		if(use >= data[i+half].a){
			W[i2+nice].a = data[i2+half].a;
			W[i2+nice].c = data[i2+half].c;
			use2 -= m[i+half].a;
			i2++;
		}else{
			g = false;
		}
	}
	int num = 1;
	for(int i = half;i >= 1;i--){
		p[num].a = W[i].a;//same
		p[num].c = W[i].c;//same
		num++;
	}
	int x = 1;
	int y = 1;
	int ans = 0;
	for(int i = 1;i <= half;i++){
		if(m[x].c != p[y].c){
			if(m[x].a >= p[y].a){
				m[x].a -= p[y].a;
				p[y].a = 0;
				y++;
				ans += p[y].a;
			}else{
				p[y].a -= m[x].a;
				m[x].a = 0;
				x++;
				ans += m[x].a;
			}
		}else{
			if(m[x].a >= p[y].a){
				m[x].a -= p[y].a;
				p[y].a = 0;
				y++;
			}else{
				p[y].a -= m[x].a;
				m[x].a = 0;
				x++;
			}
		}
	}
	cout << ans;
}
