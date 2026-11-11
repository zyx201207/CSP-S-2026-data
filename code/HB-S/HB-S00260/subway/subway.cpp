#include <bits/stdc++.h>
using namespace std;

int main(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; i++){
			cin >> a[i][j] >> t[i][j];
			f1[j][i] = 1;
		}
	}
	memset(s, 0x3f, sizeof s);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= m; k++){
				s[i][j] = min(s[i][j], t[i][k] + t[j][k]);
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= n; k++){
				if(f1[i][k] && f1[j][k]) dist[i][j] = 0;
			}
		}
		dist[i][i] = 0;
	}
	while(q--){
		cin >> st >> en;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				for(int k = 1; k <= m; k++){
					if(dist[j][i] + dist[j][k] < dist[j][k]) dist[j][k] = dist[j][i] + dist[j][k];
				}
			}
		}
	}
	//gunmugunmugunmu
	//I'm a ordinary student from WFLS, our homework is too much that I will have to have Chinese class on the metro I will go back.
	//I started learning Scratch in 6 years old. That time was wonderful. I just put on something like lego and the application can pay me a big compliment.
	//When I was seven, my mom asked me to learn Python in Xueersi. Our teacher always have written down some fantastic function before she started teaching us.
	//What we need to do just use this function and a few simple codes so we can acheive something perfect like make an own QR code. I believed nobody would have refuced it.
	//When I was in Grade 5, I have started learing C++. Something bad happed. it is too hard for me.
	//I wanted to give up. But my grandfather will never accept my opinion.Damn it!
	return 0;
}
