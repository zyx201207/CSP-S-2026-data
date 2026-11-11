#include <bits/stdc++.h>
using namespace std;
struct p{
	string name;
	int age;
	int hp;
	int max_hp;
	int atc;
	int armor;
	string a , e , q;
	int ad , ed , qd;
	int ex , qx;
};
int main(){
	p c;
	cout << "创建角色:";
	cout << "\n名称:\n";
	cin >> c.name; 
	cout << "年龄:\n";
	cin >> c.age;
	cout << "初始血量:\n";
	cin >> c.hp;
	cout << "最大血量:\n";
	cin >> c.max_hp ;
	cout << "攻击:\n";
	cin >> c.atc;
	cout << "防御\n";
	cin >> c.armor;
	cout << "普攻名称:\n";
	cin>> c.a ;
	cout << "普攻伤害:\n";
	cin >> c.ad;
	cout << "填写技能效果:\n1:攻击 , 2:加盾 , 3:回血 ， 4:辅助\n";
	cout << "e技能效果:\n";
	cin >> c.ex;
	cout << "e技能名称:\n";
	cin >> c.e;
	cout << "e技能数值:\n";
	cin >> c.ed;
	cout << "q技能效果:\n";
	cin >> c.qx;
	cout << "q技能名称:\n";
	cin >> c.q;
	cout << "q技能数值:\n";
	cin >> c.qd;
	cout << "========创建完毕========\n"; 
	cout << "名称:" << c.name << "     年龄:" << c.age <<"\n攻击:" << c.atc << "      防御:" << c.armor << "\n普攻:" << c.a << "\n  " << c.ad << "伤"  << "\ne技能:" << c.e << "\n  效果:";
	if(c.ex == 1) cout << "攻击";
	else if(c.ex == 2) cout << "加盾";
	else if(c.ex == 3) cout << "回血";
	else if(c.ex == 4) cout << "辅助";
	cout << "\n  数值:" << c.ed << "\nq技能:" << c.q << "\n  效果:";
	if(c.qx == 1) cout << "攻击";
	else if(c.qx == 2) cout << "加盾";
	else if(c.qx == 3) cout << "回血";
	else if(c.qx == 4) cout << "辅助";
	cout << "\n  数值:" << c.qd;
	cout << "\n\n";
	int s1 = c.hp / 100 , s2 = c.max_hp / 100;
	int x = 0 , y = 0;
	if(c.hp && c.max_hp > 100){
		x = c.hp / s1;
		y = c.max_hp / s2;
	}
	
	if(x > y){
		cout << "                                               " << c.max_hp << "(+" << c.hp - c.max_hp << ")/" << c.max_hp << endl;
		for(int i = 1 ; i <= x - y ; i++){
			cout << "_";
		}
		cout << "\n[";
		for(int i = 1 ; i <= y; i++){
			cout << "|";
		}
		cout << "]\n" ;
		for(int i = 1 ; i <= x - y; i++){
			cout << "-";
		}
		cout << "\n\n";
	}
	else{
		cout << "                                               " << c.hp << "/" << c.max_hp << endl;
		cout << "[";
		for(int i = 1 ; i <= c.hp ; i++){
			cout << "|";
		}
		for(int i = 1 ; i <= y - x ; i++){
			cout << " ";
		}
		cout << "]\n\n";
	}
	return 0;
}
