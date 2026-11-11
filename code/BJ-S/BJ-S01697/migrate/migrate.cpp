//Thoita simulator--league system
#include <bits/stdc++.h>
using namespace std;
int pos=1;

string members[100]={"Rubie"};

void showLeaguePage(){
    cout<<"-----------------------------------------\n";
    cout<<"             [Guild or league]\n";
    cout<<"             [RUBY] Shiny Ruby\n";
    cout<<"Our guild is the 1st of the world.--Rubie\n";
    cout<<"Members:\n";
    cout<<"Rubie (online)                    (leader)\n";
    for(int i=1;i<pos;i++){
        cout<<members[i]<<" (online)\n";
    }
    cout<<"-----------------------------------------\n";
}

int main(){
    srand(time(0));
    cout<<"Choose your character ASAP!(please remember that you only need to type the number)\nAvailable characters: 1.Flower 2.Mob\n";
    int c1;
    cin >> c1;
    if(c1==1){
        showLeaguePage();
        cout<<"Please invite some peoele to your league!\nCommand struct: /league-invite [PlayerName]\nFor example: /league-invite cncn";
        cout<<"How many people do you wanna invite? Please choose an positive integer that is less than 100. Don't be greedy!\n";
        int n1;
        cin >> n1;
        getchar();
        for(n1;n1>=1;n1--){
            printf("You have %d chance(s) left.\n",n1);
            cout<<"[Command] ";
            string tmp,name="";
            getchar();
            getline(cin,tmp);
            for(int i=14;i<tmp.size();i++) name+=tmp[i];
            bool isNew=true;
            for(int i=0;i<pos;i++){
                if(members[i]==name){
                    cout<<"Failed reason: user.alreadyInLeague()==true;\n";
                    isNew=false;
                    break;
                }
            }
            if(isNew){
                if(rand()%2){
                    cout<<name<<" joined!\n";
                    members[pos]=name;
                    pos++;
                } else{
                    cout<<name<<" declined the request.\n";
                }
            }
        }
        showLeaguePage();
    } else{
        cout<<"2333...\n";
        cout<<"Sorry but this function hasn't been fully constructed yet...";
    }
    return 0;
}
